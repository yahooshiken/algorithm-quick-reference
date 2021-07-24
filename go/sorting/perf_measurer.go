package sorting

import (
	"math/rand"
	"strconv"
	"strings"
	"time"
)

type PerfMeasurer struct {
	sorter Sorter
}

func (p PerfMeasurer) ReportPerf() string {
	b := strings.Builder{}

	sizes := []int{100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000}
	for _, size := range sizes {
		arr := make([]int, size)
		for i := range arr {
			arr[i] = i
		}

		rand.Seed(0)
		for i := size - 1; i > 0; i-- {
			j := rand.Intn(i + 1)
			arr[i], arr[j] = arr[j], arr[i]
		}

		start := time.Now()
		p.sorter.Sort(arr, "asc")
		duration := time.Since(start)

		b.WriteString("Time to sort an array of size " + strconv.Itoa(size) + " is " + duration.String() + "\n")
	}

	return b.String()
}
