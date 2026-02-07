#include "include/test.h"
#include "../../src/include/analyzed_ruby.h"

TEST(test_init_analyzed_ruby_with_simple_source)
  hb_string_T source = hb_string("x = 1");
  analyzed_ruby_T* analyzed = init_analyzed_ruby(source);

  ck_assert_ptr_nonnull(analyzed);
  ck_assert(analyzed->parsed);
  ck_assert(analyzed->valid);
  ck_assert_ptr_nonnull(analyzed->root);
  ck_assert_int_eq(analyzed->if_node_count, 0);
  ck_assert_int_eq(analyzed->elsif_node_count, 0);
  ck_assert_int_eq(analyzed->else_node_count, 0);
  ck_assert_int_eq(analyzed->end_count, 0);
  ck_assert_int_eq(analyzed->block_node_count, 0);
  ck_assert_int_eq(analyzed->block_closing_count, 0);
  ck_assert_int_eq(analyzed->case_node_count, 0);
  ck_assert_int_eq(analyzed->case_match_node_count, 0);
  ck_assert_int_eq(analyzed->when_node_count, 0);
  ck_assert_int_eq(analyzed->in_node_count, 0);
  ck_assert_int_eq(analyzed->for_node_count, 0);
  ck_assert_int_eq(analyzed->while_node_count, 0);
  ck_assert_int_eq(analyzed->until_node_count, 0);
  ck_assert_int_eq(analyzed->begin_node_count, 0);
  ck_assert_int_eq(analyzed->rescue_node_count, 0);
  ck_assert_int_eq(analyzed->ensure_node_count, 0);
  ck_assert_int_eq(analyzed->unless_node_count, 0);
  ck_assert_int_eq(analyzed->yield_node_count, 0);
  ck_assert_int_eq(analyzed->then_keyword_count, 0);
  ck_assert_int_eq(analyzed->unclosed_control_flow_count, 0);

  free_analyzed_ruby(analyzed);
END

TEST(test_init_analyzed_ruby_with_invalid_source)
  hb_string_T source = hb_string("def end end");
  analyzed_ruby_T* analyzed = init_analyzed_ruby(source);

  ck_assert_ptr_nonnull(analyzed);
  ck_assert(analyzed->parsed);
  ck_assert(!analyzed->valid);

  free_analyzed_ruby(analyzed);
END

TCase *analyzed_ruby_tests(void) {
  TCase *tc = tcase_create("Analyzed Ruby");

  tcase_add_test(tc, test_init_analyzed_ruby_with_simple_source);
  tcase_add_test(tc, test_init_analyzed_ruby_with_invalid_source);

  return tc;
}
