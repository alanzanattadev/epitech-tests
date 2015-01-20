var testCase = require('nodeunit').testCase;
var tests = require('../../../tests.js');

console.log("\x1b[36mCOCONUUUUUUUUUUUUUUUUUUUUT !\x1b[0m");

module.exports = testCase({
    'ex00': testCase(tests.getTestCase("Fruitbox",			"/tmp/epitech-tests/test00",		"/tmp/epitech-tests/ex00/outputs/out1")),
    'ex01': testCase(tests.getTestCase("Littlehands (Ya Bon !)",	"/tmp/epitech-tests/test01",		"/tmp/epitech-tests/ex01/outputs/out1")),
    'ex02': testCase(tests.getTestCase("Node.coco",			"/tmp/epitech-tests/test02",		"/tmp/epitech-tests/ex02/outputs/out1")),
    'ex03': testCase(tests.getTestCase("Jus-mix",			"/tmp/epitech-tests/test03",		"/tmp/epitech-tests/ex03/outputs/out1")),
    'ex04': testCase(tests.getTestCase("Faul Fische",			"/tmp/epitech-tests/test04",		"/tmp/epitech-tests/ex04/outputs/out1"))
});
