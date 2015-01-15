var testCase = require('nodeunit').testCase;
var tests = require('../../../tests.js');

module.exports = testCase({
    'ex00': testCase(tests.getTestCase("Basic droids",	"/tmp/epitech-tests/test00 | cat -e",	"/tmp/epitech-tests/ex00/outputs/out")),
    'ex01': testCase(tests.getTestCase("DroidMemory",	"/tmp/epitech-tests/test01 | cat -e",	"/tmp/epitech-tests/ex01/outputs/out")),
    'ex02': testCase(tests.getTestCase("Roger Roger",	"/tmp/epitech-tests/test02 | cat -e",	"/tmp/epitech-tests/ex02/outputs/out")),
    'ex03': testCase(tests.getTestCase("Carrier",	"/tmp/epitech-tests/test03 | cat -e",	"/tmp/epitech-tests/ex03/outputs/out")),
    'ex04': testCase(tests.getTestCase("Supply",	"/tmp/epitech-tests/test04 | cat -e",	"/tmp/epitech-tests/ex04/outputs/out1")),
    'ex05': testCase(tests.getTestCase("DroidFactory",	"/tmp/epitech-tests/test05 | cat -e",	"/tmp/epitech-tests/ex05/outputs/out1"))
});
