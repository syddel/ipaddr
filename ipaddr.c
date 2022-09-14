#include <arpa/inet.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main ()
{
  struct ifaddrs *ifap, *ifa;
  struct sockaddr_in6 *sa;
  //struct sockaddr_in4 *sa4;
  char addr[INET6_ADDRSTRLEN];

  if (getifaddrs(&ifap) == -1) {
      perror("getifaddrs");
      exit(1);
  }

  printf("\n------------------------------------------------------------\n");
  printf("IPv4 ADDRESSES:\n");
  printf("------------------------------------------------------------\n");
  for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
    if (ifa->ifa_addr && ifa->ifa_addr->sa_family==AF_INET) {
      getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr), addr,
        sizeof(addr), NULL, 0, NI_NUMERICHOST);
      printf("%-10s %s\n", ifa->ifa_name, addr);
    }
  }

  printf("\n------------------------------------------------------------\n");
  printf("IPv6 ADDRESSES:\n");
  printf("------------------------------------------------------------\n");
  for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
    if (ifa->ifa_addr && ifa->ifa_addr->sa_family==AF_INET6) {
      sa = (struct sockaddr_in6 *) ifa->ifa_addr;
      getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in6), addr,
                  sizeof(addr), NULL, 0, NI_NUMERICHOST);
      printf("%-10s %s\n", ifa->ifa_name, addr);
    }
  }
  printf("\n");

  freeifaddrs(ifap);
  return 0;
}
