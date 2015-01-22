var testCase = require('nodeunit').testCase;
var tests = require('../../../tests.js');

console.log("\x1b[36mOn nous a empapaouté !!!\x1b[0m");

module.exports = testCase({
  'ex00': testCase(tests.getTestCase("eval_expr",		"/tmp/epitech-tests/test00",		"/tmp/epitech-tests/ex00/outputs/out1")),
  'ex01': testCase(tests.getTestCase("DomesticKoala",		"/tmp/epitech-tests/test01",		"/tmp/epitech-tests/ex01/outputs/out1")),
  'ex02': testCase(tests.getTestCase("EventManager",		"/tmp/epitech-tests/test02",		"/tmp/epitech-tests/ex02/outputs/out1")),
  'ex03': testCase(tests.getTestCase("BF_Translator",
    "cp /tmp/epitech-tests/ex03/NO.c /tmp/epitech-tests/;" +
      "chmod 444 /tmp/epitech-tests/NO.c;" +
      "/tmp/epitech-tests/test03;" +
      "gcc -W -Wall -Wextra /tmp/epitech-tests/out.c -o /tmp/epitech-tests/out1;" +
      "/tmp/epitech-tests/out1;" +
      "gcc -W -Wall -Wextra /tmp/epitech-tests/out2.c -o /tmp/epitech-tests/out2;" +
      "/tmp/epitech-tests/out2 < /tmp/epitech-tests/ex03/inputs/in1",
    "/tmp/epitech-tests/ex03/outputs/out1")),
  'ex04': testCase(tests.getTestCase("Ratatard",		"/tmp/epitech-tests/test04",		"/tmp/epitech-tests/ex04/outputs/out1")),
  'ex05': testCase(tests.getTestCase("MutantStack",		"/tmp/epitech-tests/test05",		"/tmp/epitech-tests/ex05/outputs/out1"))
});
