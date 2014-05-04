# encoding: UTF-8
import threading
 
def func():
    print 'hello timer!'
 
timer = threading.Timer(3, func)
timer.start()
