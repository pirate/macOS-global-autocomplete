# osx-global-autocomplete
System-wide autocompleting that learns what you type and works in any app!

The idea was to have a small popup in your menubar or as a transparent dropdown,
who's autocomplete suggestions are prompted from **all words ever typed on 
the computer**.

Unfoturnately this just has too mnay downsides.  You're essentially continually keylogging
yourself for minor convenience, and it has the potential to reveal passwords or embarrassing
information in your typing history to anyone who can see your screen.

However, if you don't type anything embarrasing and have eschewed typing passwords in favor of 
a password manager, hack away, the code is free for all to use.

TODO:
 1. add helper script to train redis trie on /usr/share/dict/words, python standard library, etc.
 2. add config file to set insertion key commands
 3. finish insert code using `pyuserinput`
 4. add code to rotate /var/log/keystroke.log
 5. add hashing blacklist functionality to exclude obsenties, sensitive words, passwords, etc.
