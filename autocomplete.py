import redis

PREFIX = 'trie'
TERMINAL = '+'
r = redis.Redis(db=6)

def add_word(word):
    key = PREFIX + ':'
    pipeline = r.pipeline(True)
    for c in word:
        r.zadd(key, c, ord(c))
        key += c
    r.zadd(key, TERMINAL, 0)
    pipeline.execute()

def suggest(text):
    for c in r.zrange(PREFIX + ":" + text, 0, -1):
        if c == TERMINAL:
            yield text
        else:
            for t in suggest(text + c):
                yield t

def format_suggestions(s_list):
    s_list = list(s_list)
    l = len(list(s_list))
    if not l:
        return ''
    if l == 1:
        return '[%s]' % s_list[0]

    return '[%s],%s'[:50] % (s_list[0], ','.join(s_list[1:5]))


if __name__ == '__main__':
    last_word = ''
    insert = False
    # read any new words into the redis trie
    for line in open('/var/log/keystroke.log', 'r'):
        stripped_word = line.strip()
        if stripped_word and 3 < len(stripped_word) < 30 and '!' not in stripped_word:
            add_word(stripped_word)
        if 2 < len(stripped_word) and '!' not in stripped_word:
            last_word = stripped_word
        if stripped_word[-4:] == '!!!!':
            insert = True

    # get the suggestion for the last typed thing
    if insert:
        print 'AAAAAAA'
    elif last_word:
        print format_suggestions(suggest(last_word))
