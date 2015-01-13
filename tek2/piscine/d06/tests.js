var testCase = require('nodeunit').testCase;
var exec = require('child_process').exec;
var fs = require('fs');
var sys = require('sys');

module.exports = testCase({
    'ex00': testCase({
	'test0': function(test) {
	    exec("make -C ./ex00/", function(err, stdout, stderr) {
		if (stderr.length != 0)
		{
		    sys.print(stderr);
		    test.ok(false);
		    test.done();
		}
		else
		{
		    exec("./ex00/my_cat ./ex00/inputs/in11 ./ex00/inputs/in12", function(err, stdout, stderr) {
			fs.readFile("./ex00/outputs/out1", function(err, data) {
			    test.equal(stdout, data);
			    test.done();
			});
		    })
		}
	    });
	},
	'test1': function(test) {
	    
	    test.done();
	}
    })
});
