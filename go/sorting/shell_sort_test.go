package sorting

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestShellSort(t *testing.T) {
	arr := []int{76, 34, 67, 32, 78, 45}
	sorter := ShellSort{}

	sorted_asc := sorter.Sort(arr, "asc")
	expected_asc := []int{32, 34, 45, 67, 76, 78}
	assert.Equal(t, expected_asc, sorted_asc)

	sorted_desc := sorter.Sort(arr, "desc")
	expected_desc := []int{78, 76, 67, 45, 34, 32}
	assert.Equal(t, expected_desc, sorted_desc)

	perfMeasurer := PerfMeasurer{sorter: sorter}
	fmt.Println(perfMeasurer.ReportPerf())

}
