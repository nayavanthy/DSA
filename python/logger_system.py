"""
Design a logger system that receives a stream of messages
along with their timestamps. Each unique message should 
only be printed{" "} at most every 10 seconds (i.e. a
message printed at timestamp t will prevent other identical
messages from being printed until timestamp t + 10).

All messages will come in chronological order. Several 
messages may arrive at the same timestamp.

Implement the Logger class:

Logger() Initializes the logger object.
bool shouldPrintMessage(int timestamp, string message){" "}
Returns true if the message should be printed in the given 
timestamp, otherwise returns false.
"""

class Logger:
  def __init__(self):
    self.lastmessage = dict()
    
  def shouldPrintMessage(self, timestamp, message):
    if message in self.lastmessage and timestamp - self.lastmessage[message] < 10:
      return False;
      
    self.lastmessage[message] = timestamp
    return True 
    

if __name__ == "__main__":
  logger = Logger()
  
  print(logger.shouldPrintMessage(1, "foo"))
  print(logger.shouldPrintMessage(2, "bar"))
  print(logger.shouldPrintMessage(8, "bar"))
  print(logger.shouldPrintMessage(10, "foo"))
  print(logger.shouldPrintMessage(11, "foo"))
  