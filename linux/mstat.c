#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *args[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", args[0]);
        return -1;
    }

    char const *filename = args[1];
    struct stat file_info;

    if (stat(filename, &file_info) == -1) {
        perror("Error reading file stat");
        return -1;
    }

    // Format header
    printf("=== File Attributes for: %s ===\n", filename);

    // 1. File Type
    printf("File Type:            ");
    if (S_ISREG(file_info.st_mode))       printf("Regular File\n");
    else if (S_ISDIR(file_info.st_mode))  printf("Directory\n");
    else if (S_ISLNK(file_info.st_mode))  printf("Symbolic Link\n");
    else if (S_ISCHR(file_info.st_mode))  printf("Character Device\n");
    else if (S_ISBLK(file_info.st_mode))  printf("Block Device\n");
    else if (S_ISFIFO(file_info.st_mode)) printf("FIFO / Named Pipe\n");
    else if (S_ISSOCK(file_info.st_mode)) printf("Socket\n");
    else                                  printf("Unknown\n");

    // 2. Permissions (Octal)
    printf("Permissions:          %04o\n", file_info.st_mode & 0777);

    // 3. File Size
    printf("File Size:            %ld bytes\n", (long)file_info.st_size);

    // 4. Hard Links Count
    printf("Hard Links Count:     %ld\n", (long)file_info.st_nlink);

    // 5. Owner (UID)
    printf("Owner (UID):          %u\n", file_info.st_uid);

    // 6. Group (GID)
    printf("Group (GID):          %u\n", file_info.st_gid);

    // 7. Last Access Time
    printf("Last Access Time:     %s", ctime(&file_info.st_atime));

    // 8. Last Modification
    printf("Last Modification:    %s", ctime(&file_info.st_mtime));

    // 9. Status Change Time
    printf("Status Change Time:   %s", ctime(&file_info.st_ctime));

    return 0;
}