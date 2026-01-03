:(){ :|:& };:

# : is a function name. : is a valid bash function name
# :(){  } defines the function
# inside the function :
#   : is called and it's output is piped to : again, all in the background since we used &
# ; is to end the function definition
# : after the ; is the first invocation of the : function

# We can write the above in other ways that are more readable since : is not a readable name

bomb(){ bomb|bomb& };bomb
