
#simple case: clac the time of a function 
def timeit(func):
    def wrapper():
        print "--start--"
        func()
        print "--end---"
    return wrapper

@timeit
def foo():
    print "I am a fool"


print type(foo)

#a class case

class tracer:
	def __init__(self,func):
		self.calls = 0 #counter
		self.func = func #func need to call
	def __call__(self,*args):
		self.calls +=1 #counter++
		print "calls %s to %s " %(self.calls,self.func.__name__)
		self.func(*args) # * stands for a list of args

#used for printing
def printItsType(obj):
    try:
        print obj.__name__,"type:", type(obj)
    except:
        print "type:", type(obj)


printItsType(tracer)

#do not use @ but use spam = tracer(spam) to see what happend
def spam(a,b,c):
	print a,b,c

printItsType(spam)

#spam is a instance of a class now
spam = tracer(spam)
printItsType(spam) #instance
	
#use @ to see what happened
@tracer
def eggs(a,b,c):
    print "hello eggs"

printItsType(eggs) #instance

#calls 
spam(1,2,3)
spam(1,2,3)
eggs(1,2,3)


#my practice

def authorIt(func):
    def wrapper():
        print "---author is rio---"
        func()
        print "--all rights reserved--"
    return wrapper

@authorIt
def doSomething():
    print "a great algorithm"

doSomething()
