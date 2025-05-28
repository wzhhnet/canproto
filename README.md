# CAN Protocol Generator (`canproto`)

该项目提供一个基于 Excel 的可视化 CAN 协议生成工具 —— `CanGenerator_v2.0.xlsm`，用于快速设计并自动生成 C 语言的 CAN 报文编解码代码。支持 Motorola（大端）和 Intel（小端）两种字节序格式。

## :star2:特性

- ✅ 可视化设计 CAN 报文结构
- ✅ 支持 Intel（Little-Endian） 和 Motorola（Big-Endian）编码方式
- ✅ 自动计算每个信号的起始与结束字节/位索引
- ✅ 一键生成 CAN 编解码的 C 接口代码
- ✅ 支持多帧设计和多信号字段管理

---

## :key:使用方式

1. 打开 `CanGenerator_v2.0.xlsm` 文件（需启用宏功能）。
2. 根据字节序选择相应的工作表：
   - **Little-Endian** Sheet → 用于 Intel 编码设计
   - **Big-Endian** Sheet → 用于 Motorola 编码设计

3. 在表格中填写以下字段：

| 字段         | 含义                                                                 |
|--------------|----------------------------------------------------------------------|
| `Protocol`   | 协议名称，自定义填写，如 `intel` 或 `motorola`                        |
| `Frame`      | CAN 报文帧名称，如 `intel`                                           |
| `Length`     | 报文长度（位），自动计算，不可编辑                                    |
| `Bits`       | 当前信号占用的位宽（bit）                                             |
| `End Byte:Bit` | 信号的结束字节和位索引，自动计算，不可编辑                        |
| `Start Byte:Bit` | 信号的起始字节和位索引，自动计算，不可编辑                      |
| `Signal`     | 信号名称，用户自定义，如 `i_signal_1`                                |
| `Description`| 描述信息（可选）                                                      |

如下是一个 `Little-Endian` 示例,Protocol: intel
| Frame | Length | Bits | End Byte\:Bit | Start Byte\:Bit | Signal       | Description |
| ----- | ------ | ---- | ------------- | --------------- | ------------ | ----------- |
| intel | 64     | 1    | 0:0           | 0:0             | i\_signal\_1 |             |
|       |        | 1    | 0:1           | 0:1             | i\_signal\_2 |             |
|       |        | 1    | 0:2           | 0:2             | i\_signal\_3 |             |
|       |        | 5    | 0:7           | 0:3             | i\_signal\_4 |             |
|       |        | 32   | 4:7           | 1:0             | i\_signal\_5 |             |
|       |        | 7    | 5:6           | 5:0             | i\_signal\_6 |             |
|       |        | 8    | 6:6           | 5:7             | i\_signal\_7 |             |
|       |        | 9    | 7:7           | 6:7             | i\_signal\_8 |             |

4. 编辑完成后，点击表格上方的 `Generate Code` 按钮，会自动生成对应的 C 源代码用于报文的打包（encode）和解包（decode）。

---

## :file_folder:输出示例

生成的 C 代码将包括：

- 每个信号的打包函数（`<protocl_name>_set_<signal_name>`）
- 每个信号的解包函数（`<protocl_name>_get_<signal_name>`）
- 整体 Frame 的打包解包函数接口
- 支持多帧的结构定义和使用说明

---

## :wrench:依赖要求

- Excel 2010 及以上（启用宏）
- Windows 系统推荐（需支持 VBA 宏）

---

## :microphone:开发者说明

- `CanGenerator_v2.0.xlsm` 内部使用 VBA 脚本管理字段布局、索引自动计算和 C 代码输出。
- 若需扩展，请参考 VBA 编辑器内的模块代码进行自定义。

---

## :scroll:License

MIT License

---

## :mailbox_with_mail:联系方式
wzhhnet@gmail.com

如有问题或建议，请提交 Issue 或联系作者。


