#include <iostream>
#include <libvirt/libvirt.h>

using namespace std;

void defaultConnection(){
/*  Works in Ubuntu as regular user. Or in Fedora as root: `sudo ./learnLibvirt` But will NOT work in Fedora as a regular user.
    Solution: https://bugzilla.redhat.com/show_bug.cgi?id=1714031
*/

    int id {5};
    virConnectPtr c;
    virDomainPtr d;
    const char *name;

    c = virConnectOpen(NULL);
    d = virDomainLookupByID(c, id);
    name = virDomainGetName(d);

    printf("name of domain %d is %s\n", 2, name);
    virConnectClose(c);
}

void systemConnection(){
    /* Works for normal users! in Fedora
    https://libvirt.org/api.html
    https://libvirt.org/uri.html
    https://libvirt.org/html/libvirt-libvirt-host.html#virConnectOpen
    */

    virConnectPtr c;
    const char *uri;
    uri = "qemu:///system";
    c = virConnectOpen(uri);


    int id {2};
    virDomainPtr d;
    const char *name;
    d = virDomainLookupByID(c, id);
    name = virDomainGetName(d);
    printf("name of domain %d is %s\n", 2, name);

    virConnectClose(c);
}

int main()
{
//    defaultConnection();
    systemConnection();
    cout << "Hello world!" << endl;
    return 0;
}
