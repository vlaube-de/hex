#
# HEX Programming Language
# Copyright (C) 2013  Yanzheng Li
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, version 3 of the License.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

import os

from optparse import OptionParser

PREPEND_STRING = \
"""
/*
 * HEX Programming Language
 * Copyright (C) 2013  Yanzheng Li
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

"""

def main():
  print 'HEX header file generator'
  
  parser = OptionParser()
  parser.add_option('-p', '--path', default="./", help='File path to generate header files.')
  parser.add_option('-d', '--dest', default='headers.h', help='Destination header file.')
  parser.add_option('-s', '--prepend-string', default=True, help='Prepend string to the beginning of the file.')
  parser.add_option('-e', '--end-def', default=None, help='Custom #define at end of file.')

  options, args = parser.parse_args()

  path = options.path
  dest =  options.dest

  print 'Generating header file...'

  header_files = [os.path.join(path, file) for file in os.listdir(path) if os.path.isfile(os.path.join(path, file)) and file[-2:] == '.h']

  count = 0
  with open(dest, 'w') as f:
    if options.prepend_string:
      f.write(PREPEND_STRING);

    for header_file in header_files:
      f.write("#include \"%s\"\n" % os.path.normpath(header_file))
      count += 1

    if options.end_def:
      f.write('\n')
      f.write('#ifndef %s\n' % options.end_def)
      f.write('\t#define %s\n' % options.end_def)
      f.write('#endif /* %s */\n' % options.end_def)

  print 'Generated header file %s successfully. [%d headers added]' % (dest, count)


if __name__ == '__main__':
  main()
