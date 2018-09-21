{{ self.title() }}

## {{ _('Description') }}

This is Captain Wang's description.

## {{ _('Input Format') }}

{{ self.input_file() }}

上面会根据具体的评测环境说明输入是文件还是标准输入等。

输入第一行包含一个正整数 $n$，保证 $n \le {{ tools.hn(prob.args['n']) }}$。←这是引用 `conf.json` 中的 `args` 的 `n` 项，然后用“好看”的格式输出。“好看”的格式如 `10^9`，`1,000,000,007`。

`prob.args['n']` 还可以写成 `prob['args']['n']`。引用 `args` 项、 `data` 项、`samples` 项和 `pre` 项现在可以简写成例如 `args['n']` 或 `args.n`。表格中也一样。

`tools` 可以简写成 `tl`，除 `hn` 外，还包括内建函数如 `tl.int`，`math` 中的对象或函数如 `tl.sin`，`datetime` 中的对象或函数如 `tl.time` 类，`num2chinese` 函数（可以把数字转化成中文）。

## {{ _('Output Format') }}

{{ self.output_file() }}

输出一个字符串 `Yes`。注意不要写成 `“Yes”（不包含引号）`。

下面是自动读入样例 `1.in/ans`（存储在 `down` 文件夹内） 然后渲染到题面中；如果只有一组样例，则去掉前两行，样例仍然保存成 `1.in/ans`。其中 `1` 可以是字符串。

{% set vars = {} -%}
{%- do vars.__setitem__('sample_id', 1) -%}
{{ self.sample_text() }}

{{ self.title_sample_description() }}

这是第一组数据的样例说明。

下面是只提示存在第二组样例，但不渲染到题面中。

{% do vars.__setitem__('sample_id', 2) -%}
{{ self.sample_file() }}

## {{ _('Subtasks') }}

