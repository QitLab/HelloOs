//彭东 @ 2021.01.09
/**
 * 实现字符串在显示器上的输出
 * 说明1：写入字符ASCII码的目标地址为0xb8000起始的内存，映射到该地址的，是显卡字符模式下的显存
 * 说明2：每显示一个字符将p_strdst + 2，是因为显存中每个字符对应2B，分别为字符编码和字符显示属性
 */
void _strwrite(char* string)
{
    char* p_strdst = (char*)(0xb8000);
    while (*string)
    {

        *p_strdst = *string++;
        p_strdst += 2;
    }
    return;
}

void printf(char* fmt, ...)
{
    _strwrite(fmt);
    return;
}
