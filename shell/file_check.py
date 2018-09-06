import re
import sys

ssh_file='/var/log/secure'
ssh_map={};
total_map={};

#Sep 25 12:51:32 localhost sshd[101113]: Failed password for invalid user wuzhenru from 192.168.1.7 port 54191 ssh2
for ssh_file in sys.argv[1:]:
	ssh_map.clear()
	for line in open(ssh_file, 'r'):
		pattern = re.compile(r".+Failed.+from (.+) port.*");
		match = pattern.findall(line);
		if match :
			if match[0] in ssh_map:
				ssh_map[match[0]] += 1;
			else:
				ssh_map[match[0]] = 1;
			if match[0] in total_map:
				total_map[match[0]] += 1;
			else:
				total_map[match[0]] = 1;
	#print "\033[1;31;40m%s\033[0m"%ssh_file
	#print ssh_map;
print "\033[1;31;40mtotal list\033[0m"
for key in total_map:
	if total_map[key] > 5:
		print(key, '=>', total_map[key])
