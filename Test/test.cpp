#include "../LStack/Stack.h"
#include "gtest.h"
TEST(TStack, can_create_stack_with_positive_size)
{
	ASSERT_NO_THROW(TStack<int> a(10));
}
TEST(TStack, cant_create_too_large_size)
{
	ASSERT_ANY_THROW(TStack<int> a(1000000));
}
TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> a(-2));
}
TEST(TStack, can_create_copied_stack)
{
	TStack<int> b(5);
	ASSERT_NO_THROW(TStack<int> a(b));
}
TEST(TStack, copied_stack_is_equal_to_source_one)
{
	TStack<int> b(5);
	b.Push(1);
	b.Push(2);
	TStack<int> a(b);
	EXPECT_EQ(b, a);

}
TEST(TStack, copied_stack_has_its_own_memory)
{
	TStack<int> b(5);
	b.Push(1);
	TStack<int> a(b);
	a.Push(2);
	EXPECT_NE(b.Top(), a.Top());

}
TEST(TStack, can_push_and_pop_elements_in_lifo_order)
{
	TStack<int> a(5);
	a.Push(5);
	a.Push(20);
	a.Push(87);
	EXPECT_EQ(a.Pop(), 87);
	EXPECT_EQ(a.Pop(), 20);
	EXPECT_EQ(a.Pop(), 5);

}
TEST(TStack, throws_when_popping_from_empty_stack)
{
	TStack<int> s(5);
	ASSERT_ANY_THROW(s.Pop());
}
TEST(TStack, can_check_if_stack_is_empty)
{
	TStack<int> s(5);
	EXPECT_TRUE(s.Empty());
	s.Push(4);
	EXPECT_FALSE(s.Empty());

}
TEST(TStack, throws_when_pushing_into_full_stack)
{
	TStack<int> s(2);
	s.Push(6);
	s.Push(3);
	ASSERT_ANY_THROW(s.Push(3));
}
TEST(TStack, can_clear_stack)
{
	TStack<int> s(5);
	s.Push(1);
	s.Push(2);
	s.Clear();
	EXPECT_TRUE(s.Empty());

}
TEST(TStack, stacks_with_different_sizes_are_not_equal1)
{
	TStack<int> s1(8);
	TStack<int> s2(2);
	EXPECT_FALSE(s1 == s2);

}
TEST(TStack, stacks_with_different_sizes_are_not_equal2)
{
	TStack<int> s1(8);
	TStack<int> s2(2);
	EXPECT_TRUE(s1 != s2);

}
TEST(TStack, can_assign_stack_to_itself)
{
	TStack<int> s(5);
	s.Push(1);
	ASSERT_NO_THROW(s = s);
	EXPECT_TRUE(s == s);
}
TEST(TStack, can_assign_stacks_of_equal_size)
{
	TStack<int> s1(5);
	s1.Push(4);
	TStack<int> s2(5);
	ASSERT_NO_THROW(s2 = s1);
	EXPECT_EQ(s2, s1);

}
TEST(TStack, can_assign_stacks_of_different_size)
{
	TStack<int> s1(5);
	s1.Push(2);
	TStack<int> s2(3);
	ASSERT_NO_THROW(s2 = s1); 
	EXPECT_EQ(s2, s1);

}
TEST(TStack, compare_equal_stacks_return_true)
{
	TStack<int> s1(5);
	TStack<int> s2(5);
	s1.Push(1);
	s2.Push(1);
	EXPECT_TRUE(s1 == s2);
}
TEST(TStack, throws_when_accessing_top_on_empty_stack)
{
	TStack<int> s(8);
	ASSERT_ANY_THROW(s.Top());
}
TEST(TStack, can_peek_top_element_without_removing)
{
	TStack<int> s(3);
	s.Push(8);
	EXPECT_EQ(s.Top(), 8);
	EXPECT_FALSE(s.Empty());
}
TEST(TStack, full_stack_reports_as_full)
{
	TStack<int> s(2);
	s.Push(1);
	s.Push(7);
	EXPECT_TRUE(s.Full());
}
TEST(TStack, empty_stacks_of_same_size_are_equal)
{
	TStack<int> s1(5);
	TStack<int> s2(5);
	EXPECT_EQ(s1, s2);
}
TEST(TStack, copying_stack_does_not_modify_original)
{
	TStack<int> s(3);
	s.Push(1);
	s.Push(2);
	TStack<int> a(s);
	a.Pop();
	EXPECT_EQ(s.Top(), 2);
}
TEST(TStack, can_push_and_check_top)
{
	TStack<int> s(5);
	s.Push(11);
	EXPECT_EQ(s.Top(), 11); 
	EXPECT_EQ(s.Pop(), 11); 
	EXPECT_TRUE(s.Empty()); 
}
TEST(TStack, clear_works_correctly_on_non_empty_stack)
{
	TStack<int> s(9);
	s.Push(7);
	s.Push(2);
	s.Push(3);
	s.Clear();
	EXPECT_TRUE(s.Empty());
	EXPECT_ANY_THROW(s.Pop());
}

//..............................................................................................
TEST(TCalc, can_create_postfix) {
	TCalc c;
	c.SetInfix("2+7-5");
	EXPECT_NO_THROW(c.ToPostfix());
	c.ToPostfix();
	EXPECT_EQ(c.GetPostfix(), "2 7 + 5 - ");
}
TEST(TCalc, can_not_create_wrong_postfix) {
	TCalc c;
	c.SetInfix("8*6))");
	EXPECT_ANY_THROW(c.ToPostfix());
	c.SetInfix("((5+5");
	EXPECT_ANY_THROW(c.ToPostfix());
}
TEST(TCalc, can_add_numbers)
{
	TCalc c;
	c.SetInfix("2+4");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), 6);
	c.SetInfix("7+8");
	EXPECT_EQ(c.Calc(), 15);
}
TEST(TCalc, can_subtract_numbers)
{
	TCalc c;
	c.SetInfix("6-3");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), 3);
	c.SetInfix("7-8");
	EXPECT_EQ(c.Calc(), -1);
}
TEST(TCalc, can_multiply_numbers)
{
	TCalc c;
	c.SetInfix("6*3");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), 18);
	c.SetInfix("6*4");
	EXPECT_EQ(c.Calc(), 24);
}
TEST(TCalc, can_divide_numbers)
{
	TCalc c;
	c.SetInfix("6/3");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), 2);
	c.SetInfix("6/4");
	EXPECT_EQ(c.Calc(), 1.5);
}
TEST(TCalc, can_raises_a_number_to_a_power)
{
	TCalc c;
	c.SetInfix("9^3");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), 729);
	c.SetInfix("2^5");
	EXPECT_EQ(c.Calc(), 32);
}
TEST(TCalc, can_perform_arithmetic_expressions)
{
	TCalc c;
	c.SetInfix("6^2*7+2-1");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), 253);
	c.SetInfix("4-8+(9-6)^5+7/8+3*6");
	EXPECT_EQ(c.Calc(), 257.875);
}
TEST(TCalc, throws_when_dividing_by_zero) {
	TCalc c;
	c.SetInfix("9/0");
	c.ToPostfix();
	EXPECT_ANY_THROW(c.CalcPostfix());
	c.SetInfix("4/0");
	EXPECT_ANY_THROW(c.Calc());
}
TEST(TCalc, can_work_with_unary_minus) {
	TCalc c;
	c.SetInfix("-4+7");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), 3);
	c.SetInfix("-9+6");
	EXPECT_EQ(c.Calc(), -3);
}
TEST(TCalc, throws_when_invalid_expression) {
	TCalc c;
	c.SetInfix("+");
	c.ToPostfix();
	EXPECT_ANY_THROW(c.CalcPostfix());
	c.SetInfix("9+*3");
	c.ToPostfix();
	EXPECT_ANY_THROW(c.CalcPostfix());
	c.SetInfix("8*");
	c.ToPostfix();
	EXPECT_ANY_THROW(c.CalcPostfix());

	c.SetInfix("2+7A5");
	EXPECT_ANY_THROW(c.Calc());
	c.SetInfix("8*6))");
	EXPECT_ANY_THROW(c.Calc());
	c.SetInfix("((5+5");
	EXPECT_ANY_THROW(c.Calc());

	c.SetInfix("+");
	EXPECT_ANY_THROW(c.Calc());
	c.SetInfix("9+*3");
	EXPECT_ANY_THROW(c.Calc());
	c.SetInfix("8*");
	EXPECT_ANY_THROW(c.Calc());
}
TEST(TCalc, can_divide_positive_numbers) {
	TCalc c;
	c.SetInfix("5/2");
	EXPECT_DOUBLE_EQ(c.Calc(), 2.5);
}
TEST(TCalc, can_add_positive_decimal_and_integer) {
	TCalc c;
	c.SetInfix("3.14+5");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), 8.14);
}
TEST(TCalc, can_multiply_two_positive_numbers) {
	TCalc c;
	c.SetInfix("2.5*4");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), 10.0);
}
TEST(TCalc, can_raise_decimal_to_power) {
	TCalc c;
	c.SetInfix("2.5^3");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), 15.625);
}
TEST(TCalc, can_raise_decimal_to_fractional_power) {
	TCalc c;
	c.SetInfix("4.0^0.5");
	c.ToPostfix();
	EXPECT_EQ(c.CalcPostfix(), 2.0);
}