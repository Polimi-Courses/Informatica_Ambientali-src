#include "hanoi.h"
void init_game() {
  for (int j = 0; j < N_DISKS; ++j) {
    status[0][j] = N_DISKS - j;
  }
  for (int i = 1; i < N_STICKS; ++i)
    for (int j = 0; j < N_DISKS; ++j)
      status[i][j] = 0;
}

bool check_victory() {
  for (size_t j = 0; j < N_DISKS; ++j) {
    if (status[N_STICKS - 1][j] != N_DISKS - j)
      return false;
  }
  return true;
}

void print_disk(size_t size) {
  for (int i = 0; i < size; ++i)
    printf("__");
}
void print_stick() { printf("|"); }

void print_status() {
  for (int j = N_DISKS - 1; j >= 0; --j) {
    for (int i = 0; i < N_STICKS; ++i) {
      if (status[i][j] != 0)
        print_disk(status[i][j]);
      else
        print_stick();
      printf("\t\t");
    }
    printf("\n");
  }
}

bool get_top_disc_position_size(size_t stick, size_t *position, size_t *size) {
  if (stick >= N_STICKS || stick < 0) {
    fprintf(stderr, "stick number %u not valid, range is (0...%u)\n", stick,
            N_STICKS - 1);
    return false;
  }
  for (*position = N_DISKS; *position > 0; (*position)--) {
    printf("get_top_disc_position: stick %d, iteration %d\n", stick,
           N_DISKS - *position);
    *size = status[stick][*position - 1];
    if (*size != 0) {
      printf("get_top_disc_position: disk found with size %d\n", *size);
      break;
    }
  }
  // no disk found on stick
  if (*size == 0) {
    printf("get_top_disc_position: No disk found on stick %d\n", stick);
    return false;
  }
  (*position)--;
  printf("get_top_disc_position: Disk found on stick %u at position %u with "
         "size %u\n",
         stick, *position, *size);
  return true;
}

bool move(size_t src_stick, size_t dst_stick) {
  if (src_stick >= N_STICKS || dst_stick >= N_STICKS || src_stick < 0 ||
      dst_stick < 0) {
    fprintf(stderr, "stick number not valid, range is (0...%u)\n",
            N_STICKS - 1);
    return false;
  }
  if (src_stick == dst_stick)
    return false;

  printf("move: Moving\n");
  size_t src_top_disk_pos;
  size_t src_top_disk_size;
  printf("move: Getting src stick top position\n");
  bool b = get_top_disc_position_size(src_stick, &src_top_disk_pos,
                                      &src_top_disk_size);
  printf("move: bool %u, pos: %d, size: %d\n", b, src_top_disk_pos,
         src_top_disk_size);
  // src stick is empty, illegal move
  if (!b)
    return false;
  size_t dst_top_disk_pos;
  size_t dst_top_disk_size;
  printf("move: Getting dst stick top position\n");
  b = get_top_disc_position_size(dst_stick, &dst_top_disk_pos,
                                 &dst_top_disk_size);
  printf("move: bool: %u, pos: %d, size: %d\n", b, dst_top_disk_pos,
         dst_top_disk_size);
  // if dst stick is not empty, there is already a disk on the dst stick, so
  // compare sizes
  if (b && dst_top_disk_size < src_top_disk_size) {
    printf("move: Illegal movement\n");
    return false;
  }
  printf("move: Legal movement\n");
  // at this point, each movement is legal
  // If we have found a disk on the dst stick, we have to put the new disk on
  // top of it
  if (b) {
    dst_top_disk_pos++;
  }
  status[dst_stick][dst_top_disk_pos] = src_top_disk_size;
  status[src_stick][src_top_disk_pos] = 0;
  return true;
}
