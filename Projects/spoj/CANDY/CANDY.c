#include <stdio.h>
#include <string.h>

#define MAX_PACKET_COUNT 10000

int total(int * array, int count) {
  int i, j;
  for (i = 0, j = 0; i < count; ++i) {
    j += array[i];
  }
  return j;
}

int main(int argc, char * argv[]) {
  int packets[MAX_PACKET_COUNT + 1];
  int packet_count;
  int packet_total;
  int packet_average;
  int packet_delta;
  int i;
  while (scanf("%d", &packet_count), packet_count > 0) {
    for (i = 0; i < packet_count; ++i) {
      scanf("%d", &packets[i]);
    }
    packet_total = total(packets, packet_count);
    if (packet_total % packet_count != 0) {
      printf("-1\n");
      continue;
    }
    packet_average = packet_total / packet_count;
    packet_delta = 0;
    for (i = 0; i < packet_count; ++i) {
      if (packets[i] > packet_average) {
        packet_delta += packets[i] - packet_average;
      }
    }
    printf("%d\n", packet_delta);
  }
  return 0;
}
