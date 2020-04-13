char h2c(unsigned char a)
{
	return (a > 10 ? a + 87 : a + 48);
}

char *ft_rgb2hex(int r, int g, int b)
{
	char result[8];
	char *send;

	result[0] = '#';
	result[1] = h2c(((unsigned char)r & 0xf0) >> 4);
	result[2] = h2c((unsigned char)r & 0x0f);
	result[3] = h2c(((unsigned char)g & 0xf0) >> 4);
	result[4] = h2c((unsigned char)g & 0x0f);
	result[5] = h2c(((unsigned char)b & 0xf0) >> 4);
	result[6] = h2c((unsigned char)b & 0x0f);
	result[7] = '\0';
	send = result;
	return (send);
}
