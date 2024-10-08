##
# You must create at least 2 encrypted partitions using LVM.

##
# A SSH service will be runngin on the mandatory port 4242
# in your virtual machine. For security reasons, it must not
# be possible to connet using SSH as root.

## check current configurations
systemctl status firewalld
firewall-cmd --list-all

## modify sshd
/etc/ssh/sshd_config
- # Port 22
+ Port 4242

- PermitRootLogin yes
+ PermitRootLogin no

sudo systemctl restart sshd

## modify selinux
https://shachikunbot.com/sshd-selinux/


##
# You have to configure your operating system with the firewalld
# firewall and thus leave only port 4242 open in your virtual machine.

## modify firewalld
https://qiita.com/fk_2000/items/019b62818e34be973227


##
# The hostname of your virtual machine must be your login ending
# with 42. In my case, it should be takitaga42.
sudo hostnamectl set-hostname takitaga42
## You don't need to reboot the machine.
## Just need to exit the current session then re-login.


##
# You have to implement a strong password policy.
# Password policy:
# - Your password has to expire every 30 days.
# - The minimum number of days allowd before the modification of
#   a password will be set to 2.
# - The user has to receice a warning message 7 days before their
#   password expires.
# - You password must be at least 10 characters long. It must contain
#   an uppercase letter, a lowercase letter, and a number. Also,
#   it must not contain more than 3 consecutive identical charaters.
# - The password must not include the name of the user.
# - The following rule does not apply to the root password:
#   The password must have at least 7 characters that are not part
#   of the former password.
# - Of course, your root password has to comply with this policy.

## modify PAM
/etc/pam.d/system-auth
/etc/security/pwquality.conf
https://mseeeen.msen.jp/how-to-set-password-policy-in-centos7/



##
# You have to install and configure sudo following strict rules.
# Requirements:
# - Authentication using sudo has to be limited to 3 attempts
#   in the event of an incorrect password.
# - A custom message of your choice has to be displayed if an error
#   due to a wrong password occurswhen using sudo.
# - Each action using sudo has to be archived, both inputs and outputs.
#   The log file has to be saved in the /var/log/sudo/ folder.
# - The TTY mode has to be enabled for security reasons.
# - For security reasons too, the paths that can be used by sudo
#   must be restricted.
#   Example:
#   /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin
man sudoers
visudo


##
# In addition to the root user, a user with your login as username
# has to be present. This user has to belong to the user42 and sudo groups.
useradd takitaga42
passwd takitaga42
cat /etc/passwd | grep takitaga42
cat /etc/group | grep takitaga42



##
# You have to create a simple script called monitoring.sh. It must be
# developed in bash. At server startup, the script will display some
# information (listed below) on all terminals every 10 minutes (take a
# look at wall). The banner is optional. No error must be visible.
# Your script must always be able to display the following information:
# - The architecture of your operating system and its kernel version.
# - The number of physical processors.
# - The number of virtual processors.
# - The current available RAM on your server and its utilization rate
#   as a percentage.
# - The current available storage on your server and its utilization rate
#   as a percentage.
# - The current utilization rate of your processors as a percentage.
# - The date and time of the last reboot.
# - Whether LVM is active or not.
# - The number of active connections.
# - The number of users using the server.
# - The IPv4 address of your server and its MAC address.
# - The number of command executed with the sudo program.
