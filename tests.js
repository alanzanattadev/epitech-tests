var testCase = require('nodeunit').testCase;
var exec = require('child_process').exec;
var colors = require('colors');
var diff = require('diff');
var fs = require('fs');

Error.prepareStackTrace = function(error, stack) {
  var d = error.message;
  var ret = "";
  if (d) {
    d.forEach(function(part) {
      var color = part.added ? 'green' : part.removed ? 'red' : 'grey';
      ret += part.value[color];
    });
  }
  return ret;
};

exports.getTestCase = function(name, execCmd, diffFile) {
    ret = {};
    ret[name] = function(test) {
      exec(execCmd, function(err, stdout, stderr) {
        if (err) {
          test.ok(false);
          console.log(stdout);
          console.log(stderr);
          console.log(err);
          test.done();
        } else {
          fs.readFile(diffFile, function(err, data) {
            if (err) {
              test.ok(false);
              console.log(stdout);
              console.log(stderr);
              console.log(err);
            } else {
              if (data.toString() != stdout) {
                var d;
                if (stdout != "")
                  d = diff.diffLines(stdout, data.toString());
                else
                  d = diff.diffLines(stdout, "No output provided.");
                test.ok(false, d);
              } else {
                test.ok(true);
              }
            }
            test.done();
          });
        }
      });
    };
    return ret;
}
