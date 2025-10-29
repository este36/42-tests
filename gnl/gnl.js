import { execFileSync } from 'node:child_process';
import { readFileSync } from 'node:fs';
import { spawnSync } from 'node:child_process';

const ANSI_GREEN = "\x1b[32m";
const ANSI_RED = "\x1b[31m";
const ANSI_RESET = "\x1b[0m";

const test_gnl = process.argv[2];

function OK()
{
	process.stdout.write(ANSI_GREEN + " OK\n" + ANSI_RESET);
}

function ERROR()
{
	process.stdout.write(`${ANSI_RED + " Error!" + ANSI_RESET}\n`);
}

function exec(args) {
    const output = spawnSync(args[0], args.slice(1), { stdio: 'pipe', text: true  });
    return [output.stdout, output.stderr].join("");
}

function doFileTest(test_file)
{
	process.stdout.write(`Test: ${test_file}:`);
	const result = exec([`./${test_gnl}`, test_file]);
	const expected = readFileSync(test_file);
	if (result.toString() !== expected.toString())
	{
		ERROR();
		const debug_result = exec(['./test_gnl', test_file, '--debug'])
		console.log(`result:\n---\n${debug_result.toString()}\n---`);
		return (false);
	} else
		OK();
	return (true);
}

function testBadFileDesciptor(test_title, n, expected)
{
	const result = exec([`./${test_gnl}`, '--test', n.toString()]);
	process.stdout.write('Test: ' + test_title + ':');
	if (result.toString() !== expected)
	{
		ERROR();
		console.log(`expected: ${expected}`);
		console.log(`result: ${result}`);
		return (false);
	}
	OK();
	return (true);
}

const test_files = [
	"gnl/files/41_no_nl",
	"gnl/files/41_with_nl",
	"gnl/files/42_no_nl",
	"gnl/files/42_with_nl",
	"gnl/files/43_no_nl",
	"gnl/files/43_with_nl",
	"gnl/files/alternate_line_nl_no_nl",
	"gnl/files/alternate_line_nl_with_nl",
	"gnl/files/big_line_no_nl",
	"gnl/files/big_line_with_nl",
	"gnl/files/empty",
	"gnl/files/multiple_line_no_nl",
	"gnl/files/multiple_line_with_nl",
	"gnl/files/multiple_nlx5",
	"gnl/files/nl"
];

console.log("[Files]");
for (const test_file of test_files)
	doFileTest(test_file);

process.stdout.write("Test: stdin:");
const stdin_expected = exec(['cat', './gnl/files/multiple_line_with_nl']);
const stdin_result = exec([`./gnl/test_gnl_stdin`, test_gnl]);
if (stdin_result.toString() !== stdin_expected.toString()) {
	ERROR();
	console.log(stdin_result.toString());
	console.log(stdin_expected.toString());
} else {
	OK();
}

console.log("[Bad file descriptors]");
testBadFileDesciptor("Read after end", 1, "(null)");
testBadFileDesciptor("fd == -1", 1, "(null)");
testBadFileDesciptor("fd == 1000", 1, "(null)");

process.exit(0);
