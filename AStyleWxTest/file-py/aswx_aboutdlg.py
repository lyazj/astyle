#! /usr/bin/python3

"""Check AboutDlgBase.h to AboutDlg.h to verify that all virtual functions
   are overridden.
"""

# to disable the print statement and use the print() function (version 3 format)
from __future__ import print_function

import libastylewx      # local directory

# global variables ------------------------------------------------------------

__print_detail = False          # print line numbers and total functions
__print_functions = False           # print the functions in the lists

# -----------------------------------------------------------------------------

def main():
    """Main processing function."""

    dlggui_functions = []       # functions in AboutDlgBase.h
    dlg_functions = []          # functions in AboutDlg.h
    dlggui_path = libastylewx.get_astylewx_directory() + "/dialog/AboutDlgBase.h"
    dlg_path = libastylewx.get_astylewx_directory() + "/src/AboutDlg.h"

    libastylewx.set_text_color("yellow")
    print(libastylewx.get_python_version())
    print("AboutDlg")
    get_dlggui_functions(dlggui_functions, dlggui_path)
    get_dlg_functions(dlg_functions, dlg_path)

    find_function_diffs(dlggui_functions, dlg_functions)

    if __print_functions:
        print(dlggui_functions)
        print(dlg_functions)

# -----------------------------------------------------------------------------

def extract_void_function_name(line):
    """Extract the function name of a function with a "void' return value.
       Extracts the text between 'void' and the first opening paren.
       Returns the function name.
    """

    name_start = line.find("void")
    if name_start == -1:
        return ''
    function_name = line[name_start + len("void"):].strip()
    name_end = function_name.find('(')
    if name_end == -1:
        return ''
    function_name = function_name[:name_end].strip()
    return function_name

# -----------------------------------------------------------------------------

def find_function_diffs(dlggui_functions, dlg_functions):
    """Find differences in dlggui and dlg functions lists."""
    # A set is an unordered collection with no duplicate elements
    # converting to a 'set' will remove duplicates
    missing_functions = set(dlggui_functions) - set(dlg_functions)

    if len(missing_functions) > 0:
        missing_functions = sorted(missing_functions)
        print(missing_functions)

    diffs = len(missing_functions)
    if diffs == 0:
        print("There are NO missing function overrides!!!")
    else:
        print("There are {0} missing function overrides.".format(diffs))

# -----------------------------------------------------------------------------

def get_dlg_functions(dlg_functions, dlg_path):
    """Read the header file and save the AboutDlg 'void' functions."""

    function_total = 0      # total virtual functions for header
    lines = 0                   # current input line number
    file_in = open(dlg_path, 'r')

    for line_in in file_in:
        lines += 1
        line = line_in.strip()
        if len(line) == 0:
            continue

        # find the void functions
        if not line.startswith("void"):
            continue
        # get the function name
        virtual_function_name = extract_void_function_name(line)
        if virtual_function_name == '':
            continue
        dlg_functions.append(virtual_function_name)
        function_total += 1

    file_in.close()
    if __print_detail:
        print("{0} AboutDlg functions".format(function_total))

# -----------------------------------------------------------------------------

def get_dlggui_functions(dlggui_functions, dlggui_path):
    """Read the header file and save the AboutDlgBase 'virtual void' functions."""

    virtual_start = False       # start looking for virtual functions
    header_total = 0            # total virtual functions for header
    lines = 0                   # current input line number
    file_in = open(dlggui_path, 'r')

    for line_in in file_in:
        lines += 1
        line = line_in.strip()
        if len(line) == 0:
            continue

        # start with the following line
        if line.startswith("// Virtual event handlers"):
            virtual_start = True
            continue
        if not virtual_start:
            continue
        # find the virtual functions
        if not line.startswith("virtual void"):
            continue
        # get the function name
        virtual_function_name = extract_void_function_name(line)
        if virtual_function_name == '':
            continue
        dlggui_functions.append(virtual_function_name)
        header_total += 1

    file_in.close()
    if __print_detail:
        print("{0} AboutDlgBase functions".format(header_total))

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
    main()
    libastylewx.system_exit()

# -----------------------------------------------------------------------------
