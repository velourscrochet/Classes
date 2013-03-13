;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname MergeSort) (read-case-sensitive #t) (teachpacks ((lib "bootstrap-teachpack.rkt" "installed-teachpacks"))) (htdp-settings #(#t constructor repeating-decimal #f #t none #f ((lib "bootstrap-teachpack.rkt" "installed-teachpacks")))))
(require racket/file)

(define data (file->list "TestIntegers.txt"))

(define midpoint (/ (length data) 2))

;(reverse data)
(define (split list left)
  (cond
    [(> 2 (length list)) list]
    [(> left 0) (split (cdr list) (- left 1))]
    [else list]))

(define (LeftSplit list half) (reverse (split (reverse list) half)))
(define (RightSplit list half) (split list half))


(define (contSplit list 



