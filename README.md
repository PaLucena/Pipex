
<h1 align="center">pipex</h1>

<h2>Description</h2>
<p><strong>pipex</strong> is a project from the 42 cursus that involves creating a program to emulate the behavior of the Unix pipe. The main objective is to understand inter-process communication, file descriptors, and the redirection of standard input/output. The project requires implementing a program that takes commands and files as arguments and mimics the shell pipe functionality.</p>
<div align="center"><img src="https://github.com/PaLucena/pipex/blob/main/img/pipex.PNG"></div>

<h2>Table of Contents</h2>
<ul>
	<li><a href="#requirements">Requirements</a></li>
	<li><a href="#installation">Installation</a></li>
	<li><a href="#usage">Usage</a></li>
	<li><a href="#project-structure">Project Structure</a></li>
	<li><a href="#license">License</a></li>
</ul>

<h2 id="requirements">Requirements</h2>
<p>To compile and run the project, you will need:</p>
<ul>
	<li>A Unix operating system (Linux or macOS).</li>
	<li>gcc or any C compiler.</li>
	<li>Make.</li>
</ul>

<h2 id="installation">Installation</h2>
<p>Clone the project repository and navigate to the main directory:</p>
<pre><code>git clone https://github.com/PaLucena/pipex.git
cd pipex</code></pre>
<p>Compile the project using the included Makefile:</p>
<pre><code>make</code></pre>
<p>This will generate the <code>pipex</code> executable in the current directory.</p>

<h2 id="usage">Usage</h2>
<p>To use the pipex program, run the following command:</p>
<pre><code>./pipex file1 cmd1 cmd2 file2</code></pre>
<p>This command mimics the shell pipe behavior of:</p>
<pre><code>cat file1 | cmd1 | cmd2 > file2</code></pre>
<p>Example:</p>
<pre><code>./pipex infile "grep something" "wc -l" outfile</code></pre>

<h2 id="project-structure">Project Structure</h2>
<p>The project is organized into the following files and directories:</p>
<ul>
	<li><code>src/</code>: Contains the source code of the pipex implementation.</li>
	<li><code>include/</code>: Contains the header files.</li>
	<li><code>Makefile</code>: Build script to generate the executable.</li>
	<li><code>README.md</code>: Project documentation.</li>
</ul>

<h2 id="license">License</h2>
<p>This project is licensed under the MIT License. See the <code>LICENSE</code> file for more details.</p>
