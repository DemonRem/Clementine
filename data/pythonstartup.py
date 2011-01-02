import clementine
import sys

class __ClementineLogger__:
  def __init__(self, error):
    self._error = error
    self._buffer = ''

  def write(self, data):
    self._buffer = self._buffer + data
    i = self._buffer.find('\n')
    while i != -1:
      line = self._buffer[0:i]
      self._buffer = self._buffer[i+1:]
      i = self._buffer.find('\n')

      clementine.pythonengine.AddLogLine(line, self._error)

sys.stdout = __ClementineLogger__(False)
sys.stderr = __ClementineLogger__(True)
