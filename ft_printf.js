import { execFileSync } from 'node:child_process';

const ANSI_GREEN = "\x1b[32m";
const ANSI_RED = "\x1b[31m";
const ANSI_RESET = "\x1b[0m";

function doTest(n)
{
	const ft_stdout = execFileSync('./test_ft_printf',['--c', n.toString()]).toString();
	const c_stdout = execFileSync('./test_ft_printf',['--ft', n.toString()]).toString();
	if (ft_stdout !== c_stdout)
	{
		console.log(`Error! test number ${n.toString()}.`);
		console.log("c result:");
		console.log(`\"${c_stdout}\"`);
		console.log("ft result:");
		console.log(`\"${ft_stdout}\"`);
		return (false);
	}
	return (true);
}

for (let i = 1; i < 15; i++)
{
	if (!doTest(i)) process.exit(1);
}

process.exit(0);
