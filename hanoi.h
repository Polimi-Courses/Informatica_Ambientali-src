#ifndef _HANOI_H
#define _HANOI_H
#include <stdbool.h>
#include <stdio.h>

#define N_DISKS 3
#define N_STICKS 3

/*
 * The rows represent the sticks
 * In each stick, we can have at most N_DISKS
 * Each cell cointains an unsigned which represent the size of the disk at that
 * position. Note that the maximum size of a disk is also equal to the number of
 * disks (i.e. N_DISKS).
 */
unsigned status[N_STICKS][N_DISKS];
void init_game();
void print_disk(size_t size);
void print_stick();
void print_status();
bool get_top_disc_position_size(size_t stick, size_t *position, size_t *size);
bool move(size_t src_stick, size_t dst_stick);
bool check_victory();
#endif
