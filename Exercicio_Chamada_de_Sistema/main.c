#include <stdio.h>
#include <sys/utsname.h>

int main() {

	struct utsname b;
	uname(&b);

	printf("Operating system name: %s\n", b.sysname);
	printf("Name within \"some implementation-defined network\": %s\n", b.nodename);

	printf("Operating system release: %s\n", b.release);
	printf("Operating system version: %s\n", b.version);
	printf("Hardware identifier: %s\n", b.machine);

   return 0;
}
