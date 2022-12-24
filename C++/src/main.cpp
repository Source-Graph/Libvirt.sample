#include <iostream>
#include <libvirt/libvirt.h>

using namespace std;

void lookupDomain(){

    int id {5};
    virConnectPtr c;
    virDomainPtr d;
    const char *name;

    c = virConnectOpen(NULL);
    d = virDomainLookupByID(c, id);
    name = virDomainGetName(d);

    printf("name of domain %d is %s\n", 2, name);
}

int main()
{
    lookupDomain();
    cout << "Hello world!" << endl;
    return 0;
}
