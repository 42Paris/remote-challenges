#include <stdlib.h>

int main(int argc, const char *argv[]) {
  system("docker build . -t la-pepite && docker run la-pepite");
}
