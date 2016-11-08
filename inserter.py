import time

import pykeyboard


# TODO: Replace following two lines with the code that activate the application.
print('Activate the application 3 seconds.')
time.sleep(3)

k = pykeyboard.PyKeyboard()
k.press_key(k.left_key)
time.sleep(1) # Hold down left key for 1 second.
k.release_key(k.left_key)
