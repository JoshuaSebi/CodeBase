import keyboard # type: ignore
import time

names = ["A","B","C","D","E","F"]

for name in names:
    keyboard.write(name)
    keyboard.press_and_release('tab')
    time.sleep(0.2)