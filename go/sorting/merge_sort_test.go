package sorting

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestMergeSort(t *testing.T) {
	arr := []int{76, 34, 67, 32, 78, 45}
	sorter := MergeSort{}

	sorted_asc := sorter.Sort(arr, "asc")
	expected_asc := []int{32, 34, 45, 67, 76, 78}
	assert.Equal(t, expected_asc, sorted_asc)

	perfMeasurer := PerfMeasurer{sorter: sorter}
	fmt.Println(perfMeasurer.ReportPerf())

}
