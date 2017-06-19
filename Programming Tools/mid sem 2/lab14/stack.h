struct stack
{
  int top;
  int topNum;
  char op[15];
  int num[15];
};

void initialize(struct stack s)
{
  s.top = -1;
  s.topNum = -1;
}

void push(struct stack s, char x)
{
  s.op[s.top++] = x;
}

void pushNum(struct stack s, int x)
{
  s.num[s.topNum++] = x;
}

char pop(struct stack s)
{
  char x = s.op[s.top--];
  return x;
}

int popNum(struct stack s)
{
  int x = s.num[s.topNum--];
  return x;
}

int isEmpty(struct stack s)
{
  if(s.top == -1)
    return 1;
  return 0;
}

int numIsEmpty(struct stack s)
{
  if(s.topNum == -1)
    return 1;
  return 0;
}

char peek(struct stack s)
{
  return s.op[s.top];
}

int numPeek(struct stack s)
{
  return s.num[s.topNum];
}
