# Bug 1714031 - virsh query commands silently fail for non-root user
This is the Only solution I found that Works!  
https://bugzilla.redhat.com/show_bug.cgi?id=1714031

## Solution:
"Note that by default virsh will connect to the "session" instance. You can verify this by running 'virsh uri' which should read "qemu:///session". This starts a per-user libvirtd process which is fully isolated from the 'qemu:///system' instance accessed by root by default. This behaviour did not change. You can connect to the system instance by running 'virsh -c qemu:///system list' or alternatively by setting the LIBVIRT_DEFAULT_URI=qemu:///system environment variable on any non-root account. Authentication may still be required."
- https://bugzilla.redhat.com/show_bug.cgi?id=1714031#c1

from.sch: https://www.google.com/search?q=fedora+virsh+non+root
