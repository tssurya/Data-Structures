

template<class type>
const size_t Stack<type>::stack_size;

template<class type>
void Stack<type>::push(const value_type& x)
{
    if(top_of_stack==stack_size-1)
    {
        throw std::overflow_error("Stack Overflow");
    }
    data[++top_of_stack]=x;
    return;
}

template<typename type>
void Stack<type>::pop()
{
    if(top_of_stack==-1)
    {
        throw std::underflow_error("Stack Underflow");
    }
    --top_of_stack;
    return;
}

template<typename type>
std::ostream& operator<<(std::ostream& out, const Stack<type>& s)
{
    for(typename Stack<type>::size_type i=s.size()-1; i!=0; i--)
    {
        out<<"+---------+"<<endl;
        out<<"|"          <<setw(7)<<s.data[i]<<"|"<<((i==s.size()-1)?"<--Top":"")<<endl;
    }
    if(s.size()!=0)
        out<<"+---------+"<<endl;
    else
        out<<"STACK EMPTY"<<endl;

    return out;
}
