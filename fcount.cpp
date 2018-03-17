#include <iostream>
#include <string>
#include <dirent.h>
#include <sys/stat.h>

void ProcessDirectory(std::string directory);
void ProcessEntity(struct dirent* ent);

std::string path = "";
int file_count = 0;
int dir_count = 0;
int total_size = 0;
struct dirent* entity;
struct stat buf;

int main(int argc, char const *argv[])
{
  system("export PATH=$PATH:.");
  struct stat buf;
  if(argv == NULL) {
    path = ".";
  } else{
    path = argv[1];
  }
    std::string directory = "";
    ProcessDirectory(directory);    
    std::cout << "The total number of files in directory " << path << " is " << file_count << std::endl;
    std::cout << "The total number of directories in directory " << path << " is " << dir_count-1 << std::endl;
    std::cout << "The total number of bytes occupied by all files in directory " << path << " is " << total_size << std::endl;
    return 0;
}

void ProcessDirectory(std::string directory)
{
    std::string dirToOpen = path + directory;
    auto dir = opendir(dirToOpen.c_str());

    
    path = dirToOpen + "/";

    if(NULL == dir)
    {
        return;
    } else{
      dir_count++;
    }

    entity = readdir(dir);

    while(entity != NULL)
    {
        ProcessEntity(entity);
         if (stat(entity->d_name, &buf) >= 0) {
             total_size += buf.st_size;
          }
        entity = readdir(dir);
    }

   
    path.resize(path.length() - 1 - directory.length());
    closedir(dir);
}

void ProcessEntity(struct dirent* ent)
{
    
    if(ent->d_type == DT_DIR)
    {
        if(ent->d_name[0] == '.')
        {
            return;
        }

        
        ProcessDirectory(std::string(ent->d_name));
        return;
    }

    if(ent->d_type == DT_REG)
    {
        file_count++;
        return;
    }

}

