#include <fcntl.h>
#include <unistd.h>

void test(const char* pathname) {
  char buf[1024];
  int fd = open(pathname, O_RDONLY);
  int rc = read(fd, buf, 0);
  close(fd);
}
int test2(const char* pathname, int a, int b) {
  test(pathname);
  return a + b;
}
int test3(const char* pathname) { return test2(pathname, 1, -1); }

int main() { return test3("/dev/null"); }
