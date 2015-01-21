var testCase = require('nodeunit').testCase;
var tests = require('../../../tests.js');

console.log("\x1b[36mFische Error: CommumunicationExcption, Gros PD !\x1b[0m");

module.exports = testCase({
    'ex00': testCase(tests.getTestCase("NasaError",             "/tmp/epitech-tests/test00",		"/tmp/epitech-tests/ex00/outputs/out1")),
    'ex01': testCase(tests.getTestCase("UnitTests",             "/tmp/epitech-tests/test01",		"/tmp/epitech-tests/ex01/outputs/out")),
    'ex02': testCase(tests.getTestCase("Throw your mind",		    "/tmp/epitech-tests/test02 2>&1",		"/tmp/epitech-tests/ex02/outputs/out")),
    'ex03': testCase(tests.getTestCase("Ganter (the pointer)",  "valgrind -q --leak-check=full /tmp/epitech-tests/test03",		"/tmp/epitech-tests/ex03/outputs/out1")),
    'ex04': testCase(tests.getTestCase("Dat awesome GC", 		    "valgrind -q --leak-check=full /tmp/epitech-tests/test04 2>&1",		"/tmp/epitech-tests/ex04/outputs/out1")),
  });
