import { execFileSync } from 'node:child_process';

const TEST_COUNT = 30;
const ANSI_GREEN = "\x1b[32m";
const ANSI_RED = "\x1b[31m";
const ANSI_RESET = "\x1b[0m";

function doTest(n)
{
	const c_stdout = execFileSync('./test_ft_printf',['--c', n.toString()]);
	const ft_stdout = execFileSync('./test_ft_printf',['--ft', n.toString()]);
	process.stdout.write(`Test ${n.toString()}:`);
	if (ft_stdout.toHex() !== c_stdout.toHex())
	{
		const args = execFileSync('./test_ft_printf',['--print-args', n.toString()]).toString();
		process.stdout.write(`${ANSI_RED + " Error!" + ANSI_RESET}\n`);
		console.log(`Arguments:\t${args}`);
		console.log(`C result:\t\"${c_stdout.toString()}\"\n${c_stdout.toHex()}`);
		console.log(`FT result:\t\"${ft_stdout.toString()}\"\n${ft_stdout.toHex()}`);
		return (false);
	} else {
		process.stdout.write(ANSI_GREEN + " OK\n" + ANSI_RESET);
	}
	return (true);
}

for (let i = 1; i <= TEST_COUNT; i++)
{
	if (i == 1)
		console.log("[Mandatory]");
	else if (i == 11)
		console.log("[Bonus: min_width]");
	else if (i == 21)
		console.log("[Bonus: 0]");
	doTest(i);
	// if (!doTest(i)) process.exit(1);
}

process.exit(0);
