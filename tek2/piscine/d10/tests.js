var testCase = require('nodeunit').testCase;
var tests = require('../../../tests.js');

console.log("\x1b[36mMaxime Fischer hérite de Peon qui hérite lui meme de Victim\x1b[0m");

module.exports = testCase({
    'ex00': testCase(tests.getTestCase("test",		"/tmp/epitech-tests/test00",		"/tmp/epitech-tests/ex00/outputs/out1")),
    'ex01': testCase(tests.getTestCase("test",		"/tmp/epitech-tests/test01",		"/tmp/epitech-tests/ex01/outputs/out"))
});
