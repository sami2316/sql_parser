/*
* Copyright (c) 2015, Next Generation Intelligent Networks (nextGIN), RC.
* Institute of Space Technology
* All rights reserved.
*
* This source code is licensed under the BSD-style license found in the
* LICENSE file in the root directory of this source tree. An additional grant
* of patent rights can be found in the PATENTS file in the same directory.
*/

#include <vector>
#include "lexer.h"

using namespace std;

int main()
{
  /* ------------------------------------------------------------------------ */
  /* Test of Parser with INNER JOIN clause following the where clause */
  char buffer7[] = "SELECT users.username, process.name from users inner join "
  "process.id=users.name where users.username = 'sethwang' and users.age >=21;";
  //object to hold results
  sqlselect sqlResult;
  //parser object
  SqlLexer parser;
  //now start parsing
  sql_token t7 = parser.lexer_select(buffer7, &sqlResult);
  //check if parsing terminated properly
  assert(t7 == TOK_TERMINATOR);
  cout<<buffer7<<endl;
  // print the parsed result
  sqlResult.printTable();
  sqlResult.printColumns();
  sqlResult.printJoin();
  sqlResult.printWheres();
  sqlResult.printOrderBy();
  cout<<endl;
  
  return 0;
}
