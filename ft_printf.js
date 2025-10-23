import { execFileSync } from 'node:child_process';
import { spawnSync } from 'node:child_process';

// const TEST_COUNT = 1;
const TEST_COUNT = 200;
const ANSI_GREEN = "\x1b[32m";
const ANSI_RED = "\x1b[31m";
const ANSI_RESET = "\x1b[0m";

function exec(args) {
    const output = spawnSync(args[0], args.slice(1), { stdio: 'pipe', text: true  });
    return [output.stdout, output.stderr].join("");
}

function doTest(n)
{
	const ft_stdout = exec(['./test_ft_printf', '--ft', n.toString()]);
	const c_stdout = exec(['./test_ft_printf', '--c', n.toString()]);
	if (c_stdout.toString() === "TEST END")
		process.exit(0);
	process.stdout.write(`Test ${n.toString()}:`);
	if (c_stdout.toString() !== ft_stdout.toString())
	{
		const args = execFileSync('./test_ft_printf',['--print-args', n.toString()]).toString();
		process.stdout.write(`${ANSI_RED + " Error!" + ANSI_RESET}\n`);
		console.log(`Arguments:\t${args}`);
		console.log(`C result:\t\"${c_stdout.toString()}\"`);
		console.log(`FT result:\t\"${ft_stdout.toString()}\"`);
		console.log("");
		return (false);
	} else {
		process.stdout.write(ANSI_GREEN + " OK\n" + ANSI_RESET);
	}
	return (true);
}

for (let i = -1; i <= TEST_COUNT; i++)
{
	if (i == 0)
		console.log("[Mandatory]");
	else if (i == 11)
		console.log("[Bonus: -, min_width]");
	else if (i == 21)
		console.log("[Bonus: 0]");
	else if (i == 31)
		console.log("[Bonus: .]");
	doTest(i);
	// if (!doTest(i)) process.exit(1);
}

process.exit(0);
