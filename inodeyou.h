#ifndef INODEYOU_H_INCLUDED
#define INODEYOU_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <dirent.h>

#include <sys/stat.h>
#include <sys/types.h>

// The sleuth kit header files
#include <tsk/libtsk.h>

#include <tsk/base/tsk_os.h>
#include <tsk/fs/tsk_fs.h>
#include <tsk/img/tsk_img.h>

#define BUF_LEN 100
#define USAGE "Usage: ./inodeyou-c filesystem mountpoint [directory] (./inodeyou-c /dev/sda1 / /)\n"
#define CHECK_ROOT_ERR_MSG "You must be root to perform this function!\n"
// #define TSK_INODES_FILE "tsk_inodes.txt"
// #define FS_INODES_FILE "fs_inodes.txt"

#define usage() \
    printf(USAGE);

#define file_err_msg(msg) \
    printf("Error: File %s does not exist.\n", msg);

// Used in linked list data structure functions
typedef struct inode_ll
{
    long num;
    struct inode_ll *next;
} inodenode;

// For tsk & fs mechanisms (tsk_inode.c & fs_inode.c)
// int get_tsk_inodes(const char vol[], char root[]);
// int tsk_walk_path(TSK_FS_INFO *fs, TSK_INUM_T dir_ino_num, FILE *file);
inodenode *get_tsk_inodes(const char vol[], char dir[]);
inodenode *tsk_walk_path(TSK_FS_INFO *fs, TSK_INUM_T dir_ino_num, inodenode *tsk_ll);
void inode_to_pwd(TSK_FS_INFO *fs, TSK_INUM_T dir_ino_num);
// int get_fs_inodes(const char path[]);
inodenode *get_fs_inodes(const char path[]);

// For linked list data structure
inodenode *create_inode_ll(long value);
inodenode *insert_inode_ll(inodenode *head, long value);
int find_inode_ll(inodenode *head, long val);
void destroy_inode_ll(inodenode *head);
void print_inode_ll(inodenode *head);

#endif