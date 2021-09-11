/*
 Navicat Premium Data Transfer

 Source Server         : test
 Source Server Type    : MySQL
 Source Server Version : 100421
 Source Host           : localhost:3306
 Source Schema         : player

 Target Server Type    : MySQL
 Target Server Version : 100421
 File Encoding         : 65001
 AUTHOR                : blackdragonx61 / Mali

 Date: 10/09/2021 11:18:36
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for mailbox
-- ----------------------------
DROP TABLE IF EXISTS `mailbox`;
CREATE TABLE `mailbox`  (
  `name` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `who` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `title` varchar(25) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `message` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `gm` tinyint NOT NULL DEFAULT 0,
  `confirm` tinyint NOT NULL DEFAULT 0,
  `send_time` bigint NOT NULL DEFAULT 0,
  `delete_time` bigint NOT NULL DEFAULT 0,
  `gold` int NOT NULL DEFAULT 0,
  `won` int NOT NULL DEFAULT 0,
  `ivnum` int UNSIGNED NOT NULL DEFAULT 0,
  `icount` tinyint UNSIGNED NOT NULL DEFAULT 0,
  `socket0` int UNSIGNED NOT NULL DEFAULT 0,
  `socket1` int UNSIGNED NOT NULL DEFAULT 0,
  `socket2` int UNSIGNED NOT NULL DEFAULT 0,
  `attrtype0` tinyint NOT NULL DEFAULT 0,
  `attrvalue0` smallint NOT NULL DEFAULT 0,
  `attrtype1` tinyint NOT NULL DEFAULT 0,
  `attrvalue1` smallint NOT NULL DEFAULT 0,
  `attrtype2` tinyint NOT NULL DEFAULT 0,
  `attrvalue2` smallint NOT NULL DEFAULT 0,
  `attrtype3` tinyint NOT NULL DEFAULT 0,
  `attrvalue3` smallint NOT NULL DEFAULT 0,
  `attrtype4` tinyint NOT NULL DEFAULT 0,
  `attrvalue4` smallint NOT NULL DEFAULT 0,
  `attrtype5` tinyint NOT NULL DEFAULT 0,
  `attrvalue5` smallint NOT NULL DEFAULT 0,
  `attrtype6` tinyint NOT NULL DEFAULT 0,
  `attrvalue6` smallint NOT NULL DEFAULT 0
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

SET FOREIGN_KEY_CHECKS = 1;
