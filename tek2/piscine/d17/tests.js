var testCase = require('nodeunit').testCase;
var tests = require('../../../tests.js');

console.log("\x1b[36mSchube ne le dit pas mais il a envie de bouffer d'la schnek le coquin ;)\x1b[0m");

module.exports = testCase({
  'ex00': testCase(tests.getTestCase("Find me that",		"/tmp/epitech-tests/test00",		"/tmp/epitech-tests/ex00/outputs/out1")),
  'ex01': testCase(tests.getTestCase("XXXXXXXXXXXX",		"/tmp/epitech-tests/test01",		"/tmp/epitech-tests/ex01/outputs/out1")),
  'ex02-1': testCase(tests.getTestCase("Caesar",		"/tmp/epitech-tests/test02-1 | cat -e",		"/tmp/epitech-tests/ex02/outputs/out1")),
  'ex02-2': testCase(tests.getTestCase("OnePad",		"/tmp/epitech-tests/test02-2 | cat -e",		"/tmp/epitech-tests/ex02/outputs/out2")),
  'ex03-1': testCase(tests.getTestCase("Encryption",		"/tmp/epitech-tests/test03-1 | cat -e",		"/tmp/epitech-tests/ex03/outputs/out1")),
  'ex03-2': testCase(tests.getTestCase("Static Encryption",		"/tmp/epitech-tests/test03-2 | cat -e",		"/tmp/epitech-tests/ex03/outputs/out2"))
});
