# osx-global-autocomplete
System-wide autocompleting that learns what you type and works in any app!


Not working currently.

TODO:
 1. add helper script to train redis trie on /usr/share/dict/words, python standard library, etc.
 2. add config file to set insertion key commands
 3. finish insert code using `pyuserinput`
 4. add code to rotate /var/log/keystroke.log
 5. add hashing blacklist functionality to exclude obsenties, sensitive words, passwords, etc.
