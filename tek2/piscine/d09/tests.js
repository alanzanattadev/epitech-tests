var testCase = require('nodeunit').testCase;
var tests = require('../../../tests.js');

module.exports = testCase({
    'ex-1': testCase(tests.getTestCase("Cthulhu",		"/tmp/epitech-tests/test-1 | cat -e",	"/tmp/epitech-tests/ex-1/outputs/out1")),
    'ex00': testCase(tests.getTestCase("Character",		"/tmp/epitech-tests/test00",		"/tmp/epitech-tests/ex00/outputs/out1")),
    'ex01': testCase(tests.getTestCase("Warrior",		"/tmp/epitech-tests/test01",		"/tmp/epitech-tests/ex01/outputs/out1")),
    'ex02': testCase(tests.getTestCase("Mage and Priest",	"/tmp/epitech-tests/test02",		"/tmp/epitech-tests/ex02/outputs/out1")),
    'ex03': testCase(tests.getTestCase("Paladin",		"/tmp/epitech-tests/test03",		"/tmp/epitech-tests/ex03/outputs/out")),
    'ex04': testCase(tests.getTestCase("Hunter",		"/tmp/epitech-tests/test04",		"/tmp/epitech-tests/ex04/outputs/out"))
});
